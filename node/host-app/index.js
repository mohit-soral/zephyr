const express = require('express')
const app = express()
const bodyParser = require('body-parser')
const SerialPort = require('serialport');
const port = new SerialPort('/dev/ttyACM0', {
  baudRate: 9600
});

app.use(bodyParser.json())

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.post('/', (req, res) => {
  var payload = req.body
  var command = payload.command;
  sendCommandToArduino(command, err => {
    if (err) {
      res.sendStatus(500)
    } else {
      res.sendStatus(200)
    }
  });
})

const mqtt = require('mqtt')
const client = mqtt.connect('mqtt://test.mosquitto.org')
client.on('connect', function () {
  client.subscribe('/sachin/home/bulb')
})
client.on('message', function (topic, message) {
  let command = message.toString()
  console.log('Received by MQTT: ' + command)
  sendCommandToArduino(command, err => {
    if(err){
      console.error('Failed to send MqTT Command to Arduino. Command ' + command)
    }else{
      console.info('Successfully sent MqTT Command to Arduino. Command ' + command)
    }
  })
})

function sendCommandToArduino(command, callback) {
  const commandInt = command === "ON" ? 1 : 0
  port.write(command, (err, bytesWritten) => {
    if (err) {
      console.error('sendCommandToArduino: Error while sending command to Arduino. Error: ' + err)
      callback(err)
    } else {
      console.info('sendCommandToArduino: Successfully sent comand to Arduino. Command: ' + command)
      callback()
    }
  })
}

app.listen(8989, () => console.log('Example app listening on port 3000!'))
