/**           _   _            _
 *          | | | |          (_)
 *          | |_| | ___  _ __ _ _______  _ __
 *          |  _  |/ _ \| '__| |_  / _ \| '_ \
 *          | | | | (_) | |  | |/ / (_) | | | |
 *          \_| |_/\___/|_|  |_/___\___/|_| |_|
 *
 * This file is part of Horizon (c).
 * Copyright (c) 2018 Horizon Dev Team.
 *
 * Base Author - Sagun Khosla. (sagunxp@gmail.com)
 *
 * Under a proprietary license this file is not for use
 * or viewing without permission.
 ****************************************************/

#ifndef HORIZON_LIBRARIES_GRF_GRF_HPP
#define HORIZON_LIBRARIES_GRF_GRF_HPP

#include "DES.hpp"

#include <cstdlib>
#include <string>
#include <cstring>
#include <unordered_map>
#include <boost/filesystem/path.hpp>

enum datafile_types
{
	DATAFILE_TYPE_FILE          = 0x01, // entry is a file
	DATAFILE_TYPE_DES_MIXED     = 0x02, // encryption mode 0 (header DES + periodic DES/shuffle)
	DATAFILE_TYPE_DES_HEADER    = 0x04, // encryption mode 1 (header DES only)
};

enum grf_load_result_types
{
	GRF_LOAD_OK                  = 0,
	GRF_LOAD_PATH_ERROR          = 1,
	GRF_LOAD_INCOMPLETE_HEADER   = 2,
	GRF_LOAD_MAGIC_ERROR         = 3,
	GRF_LOAD_FORMAT_ERROR        = 4,
	GRF_LOAD_INVALID_VERSION     = 5,
	GRF_LOAD_HEADER_READ_ERROR   = 6,
	GRF_LOAD_ILLEGAL_DATA_FORMAT = 7,
	GRF_LOAD_READ_ERROR          = 8,
};

enum grf_file_error_types
{
	GRF_FILE_ERROR_NONE          = 0,
	GRF_FILE_ERROR_NAME_TOO_LONG = 1
};

enum grf_read_error_types
{
	GRE_OK                       = 0,
	GRE_NOT_FOUND                = 1,
	GRE_READ_ERROR               = 2,
	GRE_DECOMPRESS_SIZE_MISMATCH = 3,
};

struct DataFile
{
	int compressed_size; // compressed size
	int compressed_aligned_size;
	int original_size; // original size
	int entry_position; // position of entry in grf
	int hash_table_position; // position in hash table.
	int next_hash_collision; // index of next DataFile entry with same hash (-1: end of entry chain)
	char type;
	char file_name[128 - 4 * 5]; // file name
};

class GRF
{
	typedef std::unordered_map<std::string, std::shared_ptr<DataFile>> FileMapType;
	typedef std::unordered_map<std::string, grf_file_error_types> FileErrorMapType;
public:
	GRF();
	grf_load_result_types load();
	void extractAllFiles();
	void extractFile(std::string file_name, std::string output_path, clock_t begin_time);
	std::pair<grf_read_error_types, uint8_t *> read(const char *in_name, int *size);
	void decode(unsigned char *buf, size_t len, char entry_type, int entry_len);
	void decodeFull(unsigned char *buf, size_t len, int cycle);
	void decodeHeader(unsigned char *buf, size_t len);
	void decodeShuffledBytes(BIT64 *src);
	int unpack(void *dest, unsigned long *dest_len, const void *source, unsigned long source_len);
	int pack(void *dest, unsigned long *dest_len, const void *source, unsigned long source_len, int level = 6);
	uint8_t substituteObfuscatedByte(uint8_t in);

	/* Path */
	boost::filesystem::path &getGRFPath() { return _full_grf_path; }
	void setGRFPath(std::string const &path) { _full_grf_path = path; }
	/* Size */
	std::size_t getGRFSize() { return _grf_size; }
	void setGRFSize(std::size_t const &size) { _grf_size = size; }
	/* Version */
	int getGRFVersion() { return _grf_version; }
	void setGRFVersion(int version) { _grf_version = version; }
	/* Total Files */
	int getTotalFiles() { return _total_files; }
	void setTotalFiles(int total) { _total_files = total; }

	FileMapType &getFileMap() { return _file_map; }
	FileErrorMapType &getFileErrorMap() { return _file_error_map; }

private:
	boost::filesystem::path _full_grf_path;
	std::size_t _grf_size;
	int _grf_version;
	int _total_files;
	FileMapType _file_map;
	FileErrorMapType _file_error_map;
};


#endif // HORIZON_LIBRARIES_GRF_GRF_HPP