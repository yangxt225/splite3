/** @brief   本文档描述splite3日志库常用接口
 *  @file    splite3Interfaces.h
 *  @author  杨晓添
 *  @version 1.0.0
 *  @date    2017/03/12
 *  @note    注解. 参见；https://www.sqlite.org/c3ref/funclist.html
 *  @since   自从...
 */

///////////////////////////////////////////////////////////////////
/**  从配置文件confpath中读取日志配置信息到内存,首次加载有效.
 @param[in]  filename 	Database filename (UTF-8)
 @param[out]  ppDb	 	SQLite db handle
 @return     			成功打开数据库，返回SQLITE_OK,否则返回错误码，sqlite3_errmsg()函数可以获取错误信息
 @warning    警告
 @note       注解		
 @see        
*/
int sqlite3_open(const char *filename, sqlite3 **ppDb);

/**  执行多个sql语句的简便接口
 @param[in]  pDb	 	sqlite3_open打开的数据库句柄，SQLite db handle
 @param[in]  sql	 	准备执行的sql语句
 @param[in]  callback 	回调函数，如果不为NULL，sql语句执行得到每一行结果后都会调用此回调函数。
 @param[in]  data		回调函数的第一个参数， 1st argument to callback
 @param[out] errmsg 	如果不为NULL,发生错误，则存放错误消息，Error msg written here
 @return     			成功打开数据库，返回SQLITE_OK,否则返回错误码，sqlite3_errmsg()函数可以获取错误信息
 @warning    警告
 @note       注解		callback函数成功则返回0,返回非0，则sqlite3_exec返回SQLITE_ABORT 并停止执行随后的sql语句
 @see        			
*/
int sqlite3_exec(sqlite3* pDb, const char *sql, int (*callback)(void*,int,char**,char**), void * data, char **errmsg);

/**  这是一个为了向后兼容而保留下来的接口，同样用来执行sql语句
 @param[in] 	pDb	 			sqlite3_open打开的数据库句柄，SQLite db handle
 @param[in]  	zSql	 		准备执行的sql语句
 @param[out]  	pazResult 		sql语句执行结果，二位数组，行优先.
 @param[out]  	pnRow			结果行数
 @param[out] 	pnColumn 		结果列数
 @param[out] 	pzErrmsg 		如果不为NULL,发生错误，则存放错误消息，Error msg written here
 @return     					成功打开数据库，返回SQLITE_OK,否则返回错误码，sqlite3_errmsg()函数可以获取错误信息
 @warning    警告
 @note       注解				返回的结果pazResult需要使用sqlite3_free_table函数释放内存
 @see        					void sqlite3_free_table(char **result)
*/
int sqlite3_get_table(sqlite3 *db, const char *zSql, char ***pazResult, int *pnRow, int *pnColumn, char **pzErrmsg)

/**  释放由sqlite3_get_table获取的查询结果的内存
 @param[in]  result 	sqlite3_get_table中获取的查询结果。
 @return     			无
 @warning    警告
 @note       注解				
 @see        		 	sqlite3_get_table			
*/
void sqlite3_free_table(char **result)

/**  关闭数据库
 @param[in]  pDb	 	sqlite3_open打开的数据库句柄，SQLite db handle
 @return     			成功关闭数据库并释放所有相关资源，返回SQLITE_OK
 @warning    警告
 @note       注解		
 @see        
*/
int sqlite3_close(sqlite3* pdb);


