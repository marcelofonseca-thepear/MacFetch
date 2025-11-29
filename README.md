# # O programa foi pensado para ser utilizado apenas por terminal. Grande parte das funcionalidades foram retiradas da lib Hwinfo.
[![Lib](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/lfreist/hwinfo)

metódo de montagem consiste em dois passos:

- guiar o shell até as dependencias:
  ```sh
  export LD_LIBRARY_PATH="$(pwd)/lib:$LD_LIBRARY_PATH"
  ```

- executar o .sh:
  ```sh
  sh build.sh
  ```

- ou

  ```sh
  bash build.sh
  ```
### e pronto!

Após executar o arquivo shell o programa será montado e executado!
