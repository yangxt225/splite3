1. 主流linux系统一般都已经安装sqlite，只需执行命令"sqlite3",如果有一下输出：
[root@localhost pc_sqlite3]# sqlite3 
SQLite version 3.6.20
Enter ".help" for instructions
Enter SQL statements terminated with a ";"
则表示系统已经安装sqlite3。
2. 使用测试程序创建sqlite3数据库，名字zieckey.db, 内含表 SensorData。
3. sqlite3命令交互模式下打开数据库，只需执行"sqlite3 zieckey.db"则可。
4. 查看数据库信息".databases"; 查看表信息".tables"; 退出".quit".