const path = require('path')
console.log('Название файла: ', path.basename(__filename))
console.log(path.parse(__filename))