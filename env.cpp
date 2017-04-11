#include<cstdlib>
#include<iostream>

using namespace std;

int main()
{

	cout.setf(ios_base::unitbuf);
	
	cout << "GCC_HOME=" << getenv("GCC_HOME") << endl;
        cout << "HOSTNAME=" << getenv("HOSTNAME") << endl;
	cout << "SELINUX_ROLE_REQUESTED=" << getenv("SELINUX_ROLE_REQUESTED") << endl;
	cout << "XTERM=" << getenv("TERM") << endl;
	cout << "SHELL=" << getenv("SHELL") << endl;
	cout << "HISTSIZE=" << getenv("HISTSIZE") << endl;
	cout << "SSH_CLIENT=" << getenv("SSH_CLIENT") << endl;
	cout << "SELINUX_USE_CURRENT_RANGE=" << getenv("SELINUX_USE_CURRENT_RANGE") << endl;
	cout << "QTDIR=" << getenv("QTDIR") << endl;
	cout << "QTINC=" << getenv("QTINC") << endl;
	cout << "SSH_TTY=" << getenv("SSH_TTY") << endl;
	cout << "USER=" << getenv("USER") << endl;
	cout << "LD_LIBRARY_PATH=" << getenv("LD_LIBRARY_PATH") << endl;
	cout << "LS_COLORS=" << getenv("LS_COLORS") << endl;
	cout << "MAIL=" << getenv("MAIL") << endl;
	cout << "PATH=" << getenv("PATH") << endl;
	cout << "GDB_HOME=" << getenv("GDB_HOME") << endl;
	cout << "PWD=" << getenv("PWD") << endl;
	cout << "LANG=" << getenv("LANG") << endl;
	cout << "PS1=" << getenv("PS1") << endl;
	
	cout << "SELINUX_LEVEL_REQUESTED=" << getenv("SELINUX_LEVEL_REQUESTED") << endl;
	
	cout << "HISTCONTROL=" << getenv("HISTCONTROL") << endl;
	cout << "SHLVL=" << getenv("SHLVL") << endl;
	cout << "HOME=" << getenv("HOME") << endl;
	cout << "LOGNAME=" << getenv("LOGNAME") << endl;
	cout << "QTLIB=" << getenv("QTLIB") << endl;
	cout << "CVS_RSH=" << getenv("CVS_RSH") << endl;
	cout << "SSH_CONNECTION=" << getenv("SSH_CONNECTION") << endl;
	cout << "LESSOPEN=" << getenv("LESSOPEN") << endl;
	cout << "G_BROKEN_FILENAMES=" << getenv("G_BROKEN_FILENAMES") << endl;
	cout << "_=" << getenv("_") << endl;
	cout << "OLDPWD=" << getenv("OLDPWD") << endl;
	

}
