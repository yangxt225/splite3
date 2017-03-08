1. 主流linux系统一般都已经安装sqlite，只需执行命令"sqlite3",如果有一下输出：
[root@localhost pc_sqlite3]# sqlite3 
SQLite version 3.6.20
Enter ".help" for instructions
Enter SQL statements terminated with a ";"
则表示系统已经安装sqlite3。
2. 使用测试程序创建sqlite3数据库，名字 yangxt.db, 内含表 SensorData。
3. sqlite3命令交互模式下打开数据库，只需执行"sqlite3 yangxt.db"则可。
4. 查看数据库信息".databases"; 查看表信息".tables"; 退出".quit".
============================================
5. 将使用交叉编译工具(arm-none-linux-gnueabi)生成的splite3库文件拷贝到arm开发板上对应库目录；拷贝方法为 “NFS+挂载”;
注意，测试程序不要在挂载目录/mnt下直接运行，而是拷贝到其他目录(比如/home)再运行，否则会报“Database is locked”。
6. 


