Football player management system
======================================

## What is this Program?
`````````
This is the CRUD Program that you can Create, Read, Update, and Delete.
This program is that managing the totalpay of soccer players, and transfer list.
This program is a system that calculates the money according to the soccer player's playing time.
It can also manage leases, eviction and transfers.
```````````


## Function of this Program
* void add_a_record(Record[], int* count)
````````
Create a new record(Soccer Player) from the standard input
````````
* int readfile(Record records[],int* count)
````````
Create a new data record from a data file
````````
* void searchplayer(Record records[], int* count)
````````
According to user specified conditions, print a record, multiple or all records
Specified conditions : name, position
````````
* int readfile2(Record records[], int* count)
``````````
The difference of readfile and readfile2 function is that readfile function is adding a record
at existing list and readfile2 function is overwritten from existing data.
``````````
* int writefile(Record records[], int* count)
```````````
write the entire data to filesystem and export the entire data in a report format as report.txt
```````````
* int update(Record records[], int* count)
``````````
Update data from stdin
``````````
* void deleteplayer(Record records[], int* count)
``````````
Delete data from stdin
``````````
* int defragment(Record records[], int* count)
```````````
If there are empty data, you can move it to the end of record.
```````````
* void sort(Record records[], int* count)
``````
Sort data from user specified condition
Specified conditions : position, totalpay
``````



 
