/* Change this if the SERVER_NAME environment variable does not report
	the true name of your web server. */
#if 1
#define SERVER_NAME CTT2000E_embedded_server
#endif
#if 0
#define SERVER_NAME "www.ctt2000e.com"
#endif

#define SAVED_ENVIRONMENT "/tmp/cgicsave.env"

#include <stdio.h>
#include "cgic.h"
#include <string.h>
#include <stdlib.h>

int cgiMain() {
	char name[20];
	char password[20];
	char *loginName="admin";
	char *loginPassword="admin";
	if(cgiFormString("Username",name,20)!=cgiFormSuccess){
		cgiHeaderLocation("../index_login_error.html");	
	}else if(cgiFormString("Password",password,20)!=cgiFormSuccess){
		cgiHeaderLocation("../index_login_error.html");
	}else if(strcmp(name,loginName)==0&&strcmp(password,loginPassword)==0){
		cgiHeaderLocation("set.cgi");
	}else{
		cgiHeaderLocation("../index_login_error.html");
	}
	return 0;
}
	
