# Projeto de Monitoramento Ambiental com Arduino e Node-RED

## Descrição
Este projeto é um sistema de monitoramento ambiental que utiliza um Arduino para coletar dados de temperatura e umidade com um sensor DHT11 e controlar um relé com base nos dados coletados. O Node-RED é usado para fornecer uma interface de usuário para visualizar os dados e controlar o sistema remotamente.

## Funcionalidades
- Leitura de temperatura e umidade através do sensor DHT11.
- Controle de um relé para ativar ou desativar dispositivos com base em condições predefinidas.
- Interface de usuário criada com Node-RED para monitoramento e controle remoto.
- Comunicação entre Arduino e Node-RED via MQTT para uma integração fácil e eficaz.

## Pré-Requisitos

Antes de começar, certifique-se de que você tem o Docker e o Docker Compose instalados em sua máquina. Se você precisar instalar qualquer um desses, visite o site oficial do Docker para obter as instruções de instalação: https://www.docker.com/get-started

## Componentes Necessários
- Arduino Uno
- Sensor DHT11 de temperatura e umidade
- Módulo Relé
- Cabos de conexão
- Resistores apropriados
- Protoboard
- Computador com Node-RED instalado

## Configuração
### Hardware
1. Conecte o sensor DHT11 ao Arduino conforme o diagrama de circuito (incluir link para o diagrama).
2. Conecte o módulo relé ao Arduino.
3. Certifique-se de que todos os componentes estão corretamente alimentados.

### Software
#### Arduino
1. Carregue o código fornecido no diretório `MonitoramentoAmbientalMQTT` do repositório para o Arduino.
   - O código configura o Arduino para ler dados do DHT11 e enviar comandos para o relé.

#### Node-RED
1. Importe o fluxo do Node-RED do arquivo `node-red-flow.json`.
2. Configure os nós de comunicação MQTT para conectar ao broker MQTT que você está usando.
3. Ajuste os parâmetros conforme necessário para corresponder à sua configuração específica.´

## Docker
### Iniciar os Serviços
Navegue até o diretório onde o seu `docker-compose.yml` está localizado e execute o seguinte comando para iniciar todos os serviços definidos no Docker Compose:

```bash
docker-compose up -d
```

Este comando irá iniciar os containers em modo 'detached', ou seja, eles continuarão executando em segundo plano.

### Acessar Node-RED
Após iniciar os containers, você pode acessar a interface do Node-RED abrindo um navegador e visitando http://localhost:1880.

### Acessar Mosquitto MQTT Broker
O Mosquitto estará disponível na porta 1883 e pode ser acessado por qualquer cliente MQTT configurado para se conectar a http://localhost:1883.

### Parar os Serviços
Se você desejar parar todos os serviços, você pode usar:
```
docker-compose down
```
Este comando irá parar e remover todos os containers, redes e volumes criados pelo Docker Compose.

### Observação
Ao utilizar com o docker, caso o Node-RED esteja com dificuldade para conectar ao Arduino, talvez seja necessário fornecer permissões ao dispositivo `/dev/ttyUSB0`, exemplo:
```
chmod 777 /dev/ttyUSB0
```

## Execução
1. Ligue o Arduino e o sistema começará automaticamente a coletar dados e a executar a lógica de controle baseada na temperatura e umidade detectadas.
2. Acesse a interface do Node-RED no navegador para visualizar os dados e controlar o sistema remotamente.

## Contribuição
Contribuições para o projeto são bem-vindas. Se você tiver melhorias ou correções, sinta-se à vontade para forkar o repositório e enviar um pull request com suas mudanças.

## Autor
- Carlos Henrique Mesquita Gomes de Oliveira
