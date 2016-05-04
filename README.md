**PowerBroker Identity Services Open**.

PowerBroker Identity Services Open has several goals:

(a) Simplify the process of joining non-Microsoft hosts to Active Directory
    domains,
(b) Simplify the management of these hosts, and
(c) Provide a rich development platform for writing applications in
    heterogeneous networks.

Instructions on building pbis-open
======================================

The pbis-open build uses makekit (http://bkoropoff.github.io/makekit/)
While the code is portable among a variety of *nix based platforms
(Linux, Solaris, AIX, HP-UX, and OS X), this build system is 
primarily intended for Linux & FreeBSD platforms.

Before you begin, please read over this list of prerequisite development
packages (depending on your Linux distro):

  * RedHat/Fedora - gcc, glibc-devel, pam-devel, ncurses-devel,
    flex, bison, rpm-build, rpm-devel, popt-devel, libxml2-devel,
    autoconf, automake, libtool

    Optional packages: 
       o libglade2-devel - To build domainjoin-gui GTK application
       o libattr-devel   - To enable extended attribute support for the 
                           PBIS CIFS server (experimental)
       o 32bit development tools and libraries for compatibility packages
         when building on x86_64
         - glibc-devel.i686, libgcc.i686, pam-devel.i686

  * Ubuntu - build-essential, fakeroot, devscripts, debhelper,
    autoconf, automake, libtool, libncurses5-dev,
    flex, bison, libpam0g-dev, libxml2-dev, libpopt-dev

    Optional packages: 
       o libglade2-dev - To build domainjoin-gui GTK application
       o libattr1-dev  - To enable extended attribute support for the 
                         PBIS CIFS server (experimental)
       o 32bit development tools and libraries for compatibility packages
         when building on x86_64
         - ia32-libs, libc6-dev-i386, gcc-multilib

    Note: The default version of awk on some Ubuntu systems has a known bug
    which causes it to segfault when attempting to build.  You can work around
    this by installing GNU awk:

        sudo apt-get install gawk

    See https://launchpad.net/ubuntu/+source/mawk/+bug/23494 for details

The easiest way to begin a build is to run:

  $ mkdir debug && cd debug
  $ ../configure --debug
  $ make -jXX package  ## where XX is 2x CPU cores

This will build the necessary binaries and libraries and package them up into
DEBs or RPMs in the pbis-open/debug/package/ directory.

If you do not want to install using packages, you can do the following
instead, but be sure to read the note below:

  $ make -jXX
  $ sudo make install

You may view the complete set of configure options by running 

  $ ../configure --help

To generate a release tarball, run "build/mkdist" with pbis-open
as your working directory.

Note: When not installing using the local package managers (DEB or RPM),
you will need to start lwsmd and import registry files manually:

  $ sudo /etc/init.d/lwsmd start
  $ sudo bash -c 'for file in /opt/pbis/share/config/*.reg; do \
      /opt/pbis/bin/lwregshell import $file; \
    done'
  $ sudo /etc/init.d/lwmsd reload

PBIS Registry Service
=========================

The PBIS Registry Service (lwregd) is the configuration data store
used by all PBIS services.  You can view and modify the registry
settings by running /opt/pbis/bin/lwregshell as the root user.  For
example:

  $ sudo /opt/pbis/bin/lwregshell
  > cd hkey_this_machine\\services

  hkey_this_machine\services> dir
  [hkey_this_machine\services]
  [HKEY_THIS_MACHINE\Services\lsass]
  ...

  hkey_this_machine\services> cd lsass

  hkey_this_machine\services\lsass> dir
  Arguments    REG_SZ   "lsassd --syslog"
  Dependencies REG_SZ   "netlogon lwio lwreg rdr"
  Description  REG_SZ    "PBIS Security and Authentication Subsystem"
  Path         REG_SZ    "/opt/pbis/sbin/lsassd"
  Type         REG_DWORD 0x00000001 (1)

  [HKEY_THIS_MACHINE\Services\lsass\Parameters]


PBIS Service Manager
========================

The PBIS Service Manager (lwsmd) provides a service control
architecture for starting and stopping all PBIS daemons and drivers
based on a dependency graph.

The lwsmd daemon itself is managed using the standard SysV init
script:

  $ /etc/init.d/lwsmd start
  * Starting PBIS Service Manager: lwsmd              [ OK ] 

Only the registry service (lwregd) is hard coded to be started
initially.  The user space CLI for managing services is the "lwsm"
utility.

  $ lwsm list
  lwreg       running (standalone: 19415)
  dcerpc      running (standalone: 19453)
  eventlog    stopped
  lsass       running (standalone: 19475)
  lwio        running (standalone: 19438)
  rdr         running (io: 19438)
  srv         running (io: 19438)
  pvfs        running (io: 19438)
  npfs        running (io: 19438)
  netlogon    running (standalone: 19468)
  srvsvc      running (standalone: 19529)

  $ lwsm info lsass
  Service: lsass
  Description: PBIS Security and Authentication Subsystem
  Type: executable
  Autostart: no
  Path: /opt/pbis/sbin/lsassd
  Arguments: 'lsassd' '--syslog'
  Dependencies: netlogon lwio lwreg rdr

  $ lwsm stop lsass
  Stopping service reverse dependency: srvsvc
  Stopping service reverse dependency: srv
  Stopping service: lsass

  $ lwsm start srvsvc
  Starting service dependency: lsass
  Starting service dependency: srv
  Starting service: srvsvc



Getting Help
============

The main PBIS Open web site is at http://www.powerbrokeropen.org/.
From here you will find links to the project forums, and pre-built
package downloads.

====

