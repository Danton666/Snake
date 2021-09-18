Summary: snake game

Name: snake

Version: 1

Release: 1

License: Proprietary

%description
This is a simple snake game

%prep
mkdir -p bin

%build
make

%install
mkdir -p $RPM_BUILD_ROOT/snake
install Snake $RPM_BUILD_ROOT/snake

%files
/snake/Snake


