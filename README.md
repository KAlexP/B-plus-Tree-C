# B-plus-Tree-C

This is a B+ tree written in C.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [Unit Tests](#unit-testing)
- [License](#license)

## Installation
1. Clone the repository:

```bash
git clone git@github.com:KAlexP/B-plus-Tree-C.git
```
2. Install dependancies

## Contributing
1. Fork the repository
2. Create a new branch: `git checkout -b feature-name`.
3. Make your changes. 
4. Push your branch: `git push origin feature-name`.
5. Create a pull request

## Unit Testing

This project uses cunit test framework for testing. Documentation for the framework 
can be found in the link below.

[https://cunit.sourceforge.net/doc/index.html](https://cunit.sourceforge.net/doc/index.html)

## Usage

There are a few functions you need to write before you get to using the B+ Tree; 
for example the make_key function needs a HashFunc, which is just a way to make 
unique keys from each data type, for an int it is really simple

```c 
int int_key(const void *data){
	return *(const int*)data;
}
```


```c 
int main(void){
	bPlusTree tree = malloc(sizeof(bPlusTree);
	int data = malloc(sizeof(int));
	key = make_key(data,HashFunc);
	tree->root = insert(tree, key, data);

	// free memory
	return 0;
}
```

## License
This project is licensed under the [GNU General Public License v.3](LICENSE).
