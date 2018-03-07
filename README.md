# Web Clients in C++

This project makes 3 different implementations of C++ web clients:
* [cURL](https://curl.haxx.se/) web client.
* [Chilkat](https://www.chilkatsoft.com/) web client.
* Custom web client using Web Sockets.

## Dependencies

#### cURL
To install the development version of libcurl in Ubuntu, execute:
```
sudo apt-get install libcurl4-openssl-dev
```

#### Chilkat
Chilkat is a proprietary library with a limited free version. The binaries can be found in the original [website](https://www.chilkatsoft.com/) or inside the lib directory of this project.

#### Custom Client
The custom client makes use of OpenSSL to process HTTPS requests. To install OpenSSL in Ubuntu, execute:
```
$ sudo apt-get install libssl-dev
```

## Building & Running tests

To build all web clients, execute:

```
$ make all
```

To clean the build directory, execute:

```
$ make clean
```

To perform the tests, execute:

```
$ make test
```

If the build was succesful, the result should be:

```
build/test/chilkat_test (PASSED)
build/test/curl_test (PASSED)
build/test/custom_test (PASSED)
```

## Executing

After building the project. The binary for the web client will be placed at "build/client". You can run it by executing:

```
$ ./build/client <url>
```

The program will output the **Http Response Body** for that URL. 
