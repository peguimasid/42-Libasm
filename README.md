<h1 align="center">Welcome to Libasm 👋</h1>
<p align="center">🏭 The aim of this project is to get familiar with assembly language.</p>

- **Status**: Finished 
- **Result**: 110%

## Install

```sh
git clone https://github.com/peguimasid/42-Libasm.git libasm
```

## Usage

#### For x86_64 Architecture

1. Ensure you are in a x86_64 environment (`uname -m` should return `x86_64`).
2. Navigate to the project directory:
  ```sh
  cd libasm
  ```
3. Build and run tests:
  ```sh
  make test
  ```

#### For Other Architectures

If you are on a different architecture, you can simulate a Debian environment in x86_64 using Docker:
1. Ensure Docker is installed and running on your system.
2. Navigate to the project directory:
  ```sh
  cd libasm
  ```
3. Start a bash inside a Debian container:
  ```sh
  make linux
  ```
4. Run tests inside the container:
  ```sh
  make test
  ```

## Authors

👦🏼 **Guilhermo Masid**

- GitHub: [@peguimasid](https://github.com/peguimasid)
- LinkedIn: [Guilhermo Masid](https://linkedin.com/in/guilhermo-masid-494677b8)

## Show your support

If you found this project helpful, please give it a ⭐️!

