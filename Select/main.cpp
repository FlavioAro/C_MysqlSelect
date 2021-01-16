#include <mysql.h>
#include <cstdio>

int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server = "SERVER";
	char *user = "USER";
	char *password = "PASSWORD";
	char *database = "DATABASE";
	conn = mysql_init(NULL);
	mysql_real_connect(conn, server, user, password, database, 0, NULL, 0);
	mysql_query(conn, "SELECT * FROM table");
	res = mysql_use_result(conn);
	printf("id \t date\t time \t comments\t\t user\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \t %s\t %s\t %s\t\t %s\n", row[0], row[1], row[2], row[3], row[4]);
	}
	mysql_free_result(res);
	mysql_close(conn);
	
	return 0;
}
