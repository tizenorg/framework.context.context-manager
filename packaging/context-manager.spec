Name:       context-manager
Summary:    Context-Manager Server Daemon
Version:    1.0.6
Release:    1
Group:      Framework/system
License:    Samsung Proprietary
Source0:    %{name}-%{version}.tar.gz
Source1:	context-manager.service
Source2:	org.tizen.sensor.context.service
BuildRequires:  cmake
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(dbus-glib-1)
BuildRequires:  pkgconfig(json)
BuildRequires:  pkgconfig(vconf)
BuildRequires:  pkgconfig(capi-appfw-application)
%ifarch %{arm}
BuildRequires:  pkgconfig(sensor)
BuildRequires:  pkgconfig(sf_common)
%endif

Requires(preun): /usr/bin/systemctl
Requires(post): sys-assert
Requires(post): /usr/bin/systemctl
Requires(postun): /usr/bin/systemctl

%description
Context-Manager Server Daemon

%prep
%setup -q

%build
%ifarch %{arm}
%define ARCH arm
%else
%define ARCH i586
%endif

cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix} -DARCH=%{ARCH}
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install

mkdir -p %{buildroot}%{_libdir}/systemd/system/graphical.target.wants
mkdir -p %{buildroot}/opt/usr/share/context-manager
#mkdir -p %{buildroot}/usr/share/license
install -m 0644 %{SOURCE1} %{buildroot}%{_libdir}/systemd/system/context-manager.service
ln -s ../context-manager.service %{buildroot}%{_libdir}/systemd/system/graphical.target.wants/context-manager.service
mkdir -p %{buildroot}%{_datadir}/dbus-1/services
install -m 0644 %{SOURCE2} %{buildroot}%{_datadir}/dbus-1/services/
#cp LICENSE %{buildroot}/usr/share/license/context-manager
#cp LICENSE %{buildroot}/usr/share/license/capi-context-manager
chmod 755 %{buildroot}/usr/bin/contextd
chmod 777 %{buildroot}/usr/lib/libcapi-context-manager.so.1
chmod 777 %{buildroot}/usr/lib/libcapi-context-manager.so

%post
systemctl daemon-reload
if [ $1 == 1 ]; then
    systemctl restart context-manager.service
fi

%preun
if [ $1 == 0 ]; then
    systemctl stop context-manager.service
fi

%postun
systemctl daemon-reload
rm -rf /opt/usr/share/context-manager

%files
%manifest packaging/context-manager.manifest
%defattr(-,root,root,-)
/usr/bin/contextd
/opt/usr/share/context-manager
%{_libdir}/systemd/system/graphical.target.wants/context-manager.service
%{_libdir}/systemd/system/context-manager.service
%{_datadir}/dbus-1/services/org.tizen.sensor.context.service
#/usr/share/license/context-manager


%package -n capi-context-manager
Summary:    Context-Manager C API
Group:      Framework/system
Requires(post):  /sbin/ldconfig
Requires(postun):  /sbin/ldconfig

%description -n capi-context-manager
Context-Manager C API

%post -n capi-context-manager
/sbin/ldconfig

%postun -n capi-context-manager
/sbin/ldconfig

%files -n capi-context-manager
%manifest packaging/capi-context-manager.manifest
%defattr(-,root,root,-)
%{_libdir}/libcapi-context-manager.so.*
#/usr/share/license/capi-context-manager


%package -n capi-context-manager-devel
Summary:    Context-Manager C API (Development)
Group:      Framework/system
Requires:	capi-context-manager = %{version}-%{release}

%description -n capi-context-manager-devel
Context-Manager C API (DEV)

%post -n capi-context-manager-devel
/sbin/ldconfig

%postun -n capi-context-manager-devel
/sbin/ldconfig

%files -n capi-context-manager-devel
%defattr(-,root,root,-)
%{_includedir}/context-manager/*.h
%{_libdir}/pkgconfig/capi-context-manager.pc
%{_libdir}/libcapi-context-manager.so
