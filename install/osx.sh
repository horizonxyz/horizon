set -x
pushd .
brew install wget gnupg unzip
brew install mariadb lua

if ! test -f "/usr/local/include/sol.hpp"; then
	pushd /tmp;
	echo "Sol2 doesn't exist, installing from scratch!";
	git clone https://github.com/ThePhD/sol2.git;
	mkdir sol2/build;
	pushd sol2/build;
	cmake ../;
	echo "Silently building and installing Sol2...";
	sudo make install >/dev/null;
	popd;
	popd;
else
	echo "Sol2 already exists, skipping installation...";
fi

if ! test -f "/usr/local/include/sqlpp11/sqlpp11.h"; then
	pushd /tmp;
	echo "Sqlpp11 doesn't exist, installing from scratch!";
	git clone https://github.com/rbock/sqlpp11.git;
	mkdir sqlpp11/build;
	pushd sqlpp11/build;
	cmake ../;
	echo "Silently building and installing Sqlpp11...";
	sudo make install >/dev/null;
	popd;
	popd;
else
	echo "Sqlpp11 already exists, skipping installation...";
fi

if ! test -f "/usr/local/include/date/date.h"; then
	pushd /tmp;
	echo "HowardHinnant/Date library doesn't exist, installing from scratch!";
	git clone https://github.com/HowardHinnant/date.git;
	mkdir date/build;
	pushd date/build;
	cmake ../;
	sudo make install;
	popd;
	popd;
else
	echo "HowardHinnant/Date already exists, skipping installation...";
fi

if ! test -f "/usr/local/include/sqlpp11/mysql/mysql.h"; then
	pushd /tmp;
	echo "Sqlpp11-connector-mysql doesn't exist, installing from scratch!";
	git clone https://github.com/rbock/sqlpp11-connector-mysql.git;
	mkdir sqlpp11-connector-mysql/build;
	pushd sqlpp11-connector-mysql/build; 
	cmake ../ -DDATE_INCLUDE_DIR=/usr/local/include;
	echo "Silently building and installing Sqlpp11-connector-mysql...";
	sudo make install;
	popd;
	popd;
else
	echo "Sqlpp11-connector-mysql already exists, skipping installation...";
fi

brew install readline zlib boost ninja

popd;
