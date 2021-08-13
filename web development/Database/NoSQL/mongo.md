# Commands
1) see which databases exist
```
show dbs
```
2) see which collectios exist in the database
```
show collections
```
3) create new database
```
use <db_name>
```
4) see currenly working db
```
db
```
5) create a collection
```
db.<collection_name>
```
6) insert info of one object to the db
```
db.<collection_name>.insertOne({_id:<something>,<more_information_you_want>})
```

7) read info from db
```
db.<collection_name>.find()
```

8) read with filters
```
db.<collection_name>.find({name: "Pencil"})
db.<collection_name>.find({price: {$gt: 1}})
```

9) read only specific field from query (this will return us only the name)
```
db.<collection_name>.find({_id: 1}, {name: 1, _id: 0})
```

10) update data in database
```
db.<collection_name>.updateOne({_id: 1},{$set: {stock: 32}})
```
11) delete data from database
```
db.<collection_name>.deleteOne({_id: 1})
```

12) delete database
```
use <db_name>
db.dropDatabase()
```