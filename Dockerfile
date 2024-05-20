FROM nodered/node-red

RUN npm i --unsafe-perm node-red-admin
RUN npm i --unsafe-perm node-red-node-arduino
RUN npm i --unsafe-perm node-red-dashboard
RUN npm i --unsafe-perm node-red-node-serialport
