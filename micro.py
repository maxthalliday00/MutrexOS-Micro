import requests

def baixar_arquivo(url, nome_arquivo_local):
    try:
        resposta = requests.get(url, stream=True)
        resposta.raise_for_status()

        with open(nome_arquivo_local, 'wb') as f:
            for chunk in resposta.iter_content(chunk_size=8192): 
                if chunk:
                    f.write(chunk)
        return True
    except requests.exceptions.HTTPError as errh:
        print ("Http Error:", errh)
    except requests.exceptions.ConnectionError as errc:
        print ("Error Connecting:", errc)
    except requests.exceptions.Timeout as errt:
        print ("Timeout Error:", errt)
    except requests.exceptions.RequestException as err:
        print ("OOps: Something Else", err)
    return False

def main():
    arquivo_mirrors = 'mirrors.txt'
    nome_arquivo_local = 'arquivo_desejado.zip'  # Modifique conforme necessário

    with open(arquivo_mirrors, 'r') as file:
        for url in file:
            print(f'Tentando baixar o arquivo de {url.strip()}')
            if baixar_arquivo(url.strip(), nome_arquivo_local):
                print(f'Arquivo baixado com sucesso de {url.strip()}')
                break
            else:
                print(f'Falha ao baixar de {url.strip()}, tentando próximo mirror.')

if __name__ == '__main__':
    main()
