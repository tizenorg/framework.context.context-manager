Name:       libcore-context-manager
Summary:    Tizen Contextual Service Framework Native API
Version:    1.1.2
Release:    1
Group:      Framework/context
License:    Apache License, Version 2.0
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  cmake
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(capi-system-info)
BuildRequires:  pkgconfig(sensor)
Requires(post):  /sbin/ldconfig
Requires(postun):  /sbin/ldconfig

%ifarch %{arm}
%define ARCH arm
%else
%define ARCH i586
%endif

%description
Tizen Contextual Service Framework Native API

%prep
%setup -q

%build
MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`

export   CFLAGS+=" -Werror -Wextra -Wcast-align -Wcast-qual -Wshadow -Wwrite-strings -Wswitch-default"
export CXXFLAGS+=" -Werror -Wextra -Wcast-align -Wcast-qual -Wshadow -Wwrite-strings -Wswitch-default -Wnon-virtual-dtor -Wno-c++0x-compat"

#export  CFLAGS+=" -Wno-array-bounds -Wno-ignored-qualifiers"
export   CFLAGS+=" -Wno-unused-parameter -Wno-empty-body"
export CXXFLAGS+=" -Wno-unused-parameter -Wno-empty-body"

export   CFLAGS+=" -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-strict-aliasing -fno-unroll-loops -fsigned-char -fstrict-overflow -fno-common"
export CXXFLAGS+=" -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-strict-aliasing -fno-unroll-loops -fsigned-char -fstrict-overflow"

export CFLAGS="$CFLAGS -DTIZEN_ENGINEER_MODE"
export CXXFLAGS="$CXXFLAGS -DTIZEN_ENGINEER_MODE"
export FFLAGS="$FFLAGS -DTIZEN_ENGINEER_MODE"

cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix} -DARCH=%{ARCH} -DMAJORVER=${MAJORVER} -DFULLVER=%{version} -DPROFILE=%{PROFILE}
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install

mkdir -p %{buildroot}/usr/share/license
cp LICENSE %{buildroot}/usr/share/license/libcore-context-manager

%post
/sbin/ldconfig

%postun
/sbin/ldconfig

%files
%manifest packaging/libcore-context-manager.manifest
%defattr(-,root,root,-)
%{_libdir}/libcore-context-manager.so.*
/usr/share/license/libcore-context-manager

%package devel
Summary:	Tizen Contextual Service Framework Native API (Development)
Group:		Framework/context
Requires:	libcore-context-manager = %{version}-%{release}

%description devel
Tizen Contextual Service Framework Native API (Development)

%post devel
/sbin/ldconfig

%postun devel
/sbin/ldconfig

%files devel
%defattr(-,root,root,-)
%{_includedir}/context-manager/*.h
%{_libdir}/pkgconfig/libcore-context-manager.pc
%{_libdir}/libcore-context-manager.so
