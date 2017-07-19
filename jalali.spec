Name:          jalali
Version:       1.0.0
Release:       1%{?dist}
Summary:       jalali library from SaminRay ICT Co

Group:	bugjoo-team
License:  Pre
URL:      http://www.bugjoo.ir/
Source0:   jalali-1.0.0.tgz
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

#BuildRequires:  
#Requires:
       
%description
jalali tools
%package        devel
Summary:        Headers and libraries for jalali
Group:          Development/Libraries
Requires:       %{name} = %{version}-%{release}
%description	devel
jalali devel
%prep
%setup -q


%build
%configure --prefix=/usr 
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT


%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root,-)
/usr/lib64/libjalali.la
/usr/lib64/libjalali.so
/usr/lib64/libjalali.so.1
/usr/lib64/libjalali.so.1.0

%files devel
%defattr(-,root,root,-)
/usr/lib64/pkgconfig/libjalali.pc
/usr/include/jalali/jalali.h
/usr/include/jalali/jalali.tcc

%postun -p /sbin/ldconfig

%changelog
