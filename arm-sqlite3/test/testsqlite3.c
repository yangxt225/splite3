#include <stdio.h>  
#include <stdlib.h>  
#include "sqlite3.h"  
#define _DEBUG_  

int main( void )  
{  
	sqlite3 *db=NULL;  
	char *zErrMsg = 0;  
	int rc;  

	rc = sqlite3_open("yangxt.db", &db); //打开指定的数据库文件,如果不存在将创建一个同名的数据库文件  
	if( rc )  
	{  
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));  
		sqlite3_close(db);  
		exit(1);  
	}  
	else printf("You have opened a sqlite3 database named yangxt.db successfully!\nCongratulations! Have fun !  ^-^ \n");  

	//创建一个表,如果该表存在，则不创建，并给出提示信息，存储在 zErrMsg 中  
	char *sql = "CREATE TABLE SensorData(\
		ID INTEGER PRIMARY KEY,\
		SensorID INTEGER,\
		SiteNum INTEGER,\
		Time VARCHAR(12),\
		SensorParameter REAL\
	);" ;  
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );  
	#ifdef _DEBUG_  
		printf("zErrMsg = %s \n", zErrMsg);  
	#endif  

	//插入数据   
	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 1 , 1 , '200605011206', 18.9 );" ;  
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );  

	sql = "INSERT INTO \"SensorData\" VALUES(NULL , 1 , 1 , '200605011306', 16.4 );" ;  
	sqlite3_exec( db , sql , 0 , 0 , &zErrMsg );  

	int nrow = 0, ncolumn = 0;  
	char **azResult; //二维数组存放结果  
	//查询数据  
	/* 
	int sqlite3_get_table(sqlite3*, const char *sql,char***result , int *nrow , int *ncolumn ,char **errmsg ); 
	result中是以数组的形式存放你所查询的数据，首先是表名，再是数据。 
	nrow ,ncolumn分别为查询语句返回的结果集的行数，列数，没有查到结果时返回0 
	*/  
	sql = "SELECT * FROM SensorData ";  
	sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );  
	int i = 0 ;  
	printf( "row:%d column=%d \n" , nrow , ncolumn );  
	printf( "\nThe result of querying is : \n" );  

	for( i=0 ; i<( nrow + 1 ) * ncolumn ; i++ ){  
		printf("%s|  ", azResult[i]);
		if(i!=0 && ((i+1)%5 == 0))
			printf("\n");
	}
	//释放掉  azResult 的内存空间  
	sqlite3_free_table( azResult );  

	#ifdef _DEBUG_  
		printf("\n");
		printf("zErrMsg = %s \n", zErrMsg);  
	#endif  
	sqlite3_close(db); //关闭数据库  
	return 0;    
}  