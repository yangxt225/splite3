/** @brief   ���ĵ�����splite3��־�ⳣ�ýӿ�
 *  @file    splite3Interfaces.h
 *  @author  ������
 *  @version 1.0.0
 *  @date    2017/03/12
 *  @note    ע��. �μ���https://www.sqlite.org/c3ref/funclist.html
 *  @since   �Դ�...
 */

///////////////////////////////////////////////////////////////////
/**  �������ļ�confpath�ж�ȡ��־������Ϣ���ڴ�,�״μ�����Ч.
 @param[in]  filename 	Database filename (UTF-8)
 @param[out]  ppDb	 	SQLite db handle
 @return     			�ɹ������ݿ⣬����SQLITE_OK,���򷵻ش����룬sqlite3_errmsg()�������Ի�ȡ������Ϣ
 @warning    ����
 @note       ע��		
 @see        
*/
int sqlite3_open(const char *filename, sqlite3 **ppDb);

/**  ִ�ж��sql���ļ��ӿ�
 @param[in]  pDb	 	sqlite3_open�򿪵����ݿ�����SQLite db handle
 @param[in]  sql	 	׼��ִ�е�sql���
 @param[in]  callback 	�ص������������ΪNULL��sql���ִ�еõ�ÿһ�н���󶼻���ô˻ص�������
 @param[in]  data		�ص������ĵ�һ�������� 1st argument to callback
 @param[out] errmsg 	�����ΪNULL,�����������Ŵ�����Ϣ��Error msg written here
 @return     			�ɹ������ݿ⣬����SQLITE_OK,���򷵻ش����룬sqlite3_errmsg()�������Ի�ȡ������Ϣ
 @warning    ����
 @note       ע��		callback�����ɹ��򷵻�0,���ط�0����sqlite3_exec����SQLITE_ABORT ��ִֹͣ������sql���
 @see        			
*/
int sqlite3_exec(sqlite3* pDb, const char *sql, int (*callback)(void*,int,char**,char**), void * data, char **errmsg);

/**  ����һ��Ϊ�������ݶ����������Ľӿڣ�ͬ������ִ��sql���
 @param[in] 	pDb	 			sqlite3_open�򿪵����ݿ�����SQLite db handle
 @param[in]  	zSql	 		׼��ִ�е�sql���
 @param[out]  	pazResult 		sql���ִ�н������λ���飬������.
 @param[out]  	pnRow			�������
 @param[out] 	pnColumn 		�������
 @param[out] 	pzErrmsg 		�����ΪNULL,�����������Ŵ�����Ϣ��Error msg written here
 @return     					�ɹ������ݿ⣬����SQLITE_OK,���򷵻ش����룬sqlite3_errmsg()�������Ի�ȡ������Ϣ
 @warning    ����
 @note       ע��				���صĽ��pazResult��Ҫʹ��sqlite3_free_table�����ͷ��ڴ�
 @see        					void sqlite3_free_table(char **result)
*/
int sqlite3_get_table(sqlite3 *db, const char *zSql, char ***pazResult, int *pnRow, int *pnColumn, char **pzErrmsg)

/**  �ͷ���sqlite3_get_table��ȡ�Ĳ�ѯ������ڴ�
 @param[in]  result 	sqlite3_get_table�л�ȡ�Ĳ�ѯ�����
 @return     			��
 @warning    ����
 @note       ע��				
 @see        		 	sqlite3_get_table			
*/
void sqlite3_free_table(char **result)

/**  �ر����ݿ�
 @param[in]  pDb	 	sqlite3_open�򿪵����ݿ�����SQLite db handle
 @return     			�ɹ��ر����ݿⲢ�ͷ����������Դ������SQLITE_OK
 @warning    ����
 @note       ע��		
 @see        
*/
int sqlite3_close(sqlite3* pdb);


