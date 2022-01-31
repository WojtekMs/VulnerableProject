# CWE-89
This code is vulnerable to the [CWE-89 "SQL Injection"](http://cwe.mitre.org/data/definitions/89.html) weakness, you can experiment with it yourself.

## Dependencies
To build this application you need:
- docker (along with docker-compose)

## Run example

First, start MySQL DB server
```bash
docker-compose up -d
```

Build and run the application
```bash
docker build . -t cwe-89
docker run -it --network cwe-89_default
```

You can filter SQL query results by the product description. Observe that it is possible to execute arbitrary SQL code if you insert specially forged SQL statement.  
For example: `'; SHOW TABLES; -- `

## Apply patch
You can apply patch by:
```bash
git apply sql_injection_fix.diff
```

Now if you build and run the docker container again and try to execute the above mentioned statement you should get 0 results.

## Reference
This example is consciously created for the purpose of SQL injection demonstration.
