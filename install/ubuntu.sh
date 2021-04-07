pushd .

pushd /tmp
CMAKE_URL="https://github.com/Kitware/CMake/releases/download/v3.20.0-rc4/cmake-3.20.0-rc4-linux-x86_64.tar.gz"
mkdir cmake && wget --quiet -O - ${CMAKE_URL} | tar --strip-components=1 -xz -C cmake
CMAKE_DIR="/tmp/cmake/bin"
echo "CMake Dir: ${CMAKE_DIR}"
ls -al ${CMAKE_DIR}

BOOST_URL="https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0.tar.gz"
mkdir boost && wget --quiet -O - ${BOOST_URL} | tar --strip-components=1 -xz -C boost
pushd boost;
./bootstrap.sh --with-libraries=locale,filesystem,log,test
./b2
./b2 install
popd

popd

if ! test -f "/usr/local/include/sol.hpp"; then
	echo "Sol2 doesn't exist, installing from scratch!";
	pushd /tmp;
	git clone https://github.com/ThePhD/sol2.git;
	mkdir sol2/build;
	pushd sol2/build;
	./../../cmake/bin/cmake ../;
	ls -al ../../cmake/bin;
	echo "Silently building and installing Sol2...";
	sudo make install >/dev/null;
	popd;
	popd;
else
	echo "Sol2 already exists, skipping installation...";
fi

if ! test -f "/usr/local/include/date/date.h"; then
	pushd /tmp;
	echo "Date library doesn't exist, installing from scratch!";
	git clone https://github.com/HowardHinnant/date.git;
	mkdir date/build;
	pushd date/build;
	cmake ../;
	sudo make install;
	popd;
	popd;
else
	echo "Sqlpp11-connector-mysql already exists, skipping installation...";
fi

if ! test -f "/usr/local/include/sqlpp11/sqlpp11.h"; then
	pushd /tmp;
	echo "Sqlpp11 doesn't exist, installing from scratch!";
	git clone https://github.com/rbock/sqlpp11.git;
	mkdir sqlpp11/build;
	pushd sqlpp11/build;
	./../../cmake/bin/cmake ../;
	sudo make install;
	popd;
	popd;
else
	echo "Sqlpp11 already exists, skipping installation...";
fi

if ! test -f "/usr/local/include/sqlpp11/mysql/mysql.h"; then
	pushd /tmp;
	echo "Sqlpp11-connector-mysql doesn't exist, installing from scratch!";
	git clone https://github.com/rbock/sqlpp11-connector-mysql.git;
	mkdir sqlpp11-connector-mysql/build;
	pushd sqlpp11-connector-mysql/build;
	./../../cmake/bin/cmake ../;
	sudo make install;
	popd;
	popd;
else
	echo "Sqlpp11-connector-mysql already exists, skipping installation...";
fi

sudo apt-get -y install libreadline-dev lua5.3 liblua5.3-dev zlib1g-dev mariadb-server mariadb-client ninja-build;

popd;
