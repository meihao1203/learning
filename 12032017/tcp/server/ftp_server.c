#include "ftp.h"
void sig_handle(int signum)
{
	while(waitpid(-1, NULL, WNOHANG) > 0) ;
}
int main(int argc, char* argv[])// conf_file path
{
	int pid ;
	int conn_num = 0 ;
	char log_buf[128];
	char ip[16] = "" ;
	char port[10]= "";
	psession_t ps ;

	signal(17, sig_handle);
	ftp_init_from_file(argv[1], ip, port );

	socket_t fd_server = socket_server(ip, port);
	socket_t fd_client ; 
	if(fd_server == -1)
	{
		ERR_EXIT("socket");
	}
	while(1)
	{
		fd_client = accept(fd_server, NULL, NULL);
		if(fd_client == -1)
		{
			ERR_EXIT("accept");
		}
		bzero(log_buf, 128);
		sprintf(log_buf, "%d connect\n",++conn_num );
		write(1, log_buf, strlen(log_buf));
		
		ps = (psession_t)calloc(1, sizeof(*ps));
		ps ->sess_sfd = fd_client ;
		pid = fork() ;
		if(pid == 0)
		{
			client_handle(ps);
			exit(1);
		}
		free(ps);
	}

}
