
import EventEmitter from 'events';



class Tracker extends EventEmitter {
    log(message, fileName) {

        message = __dirname;
        fileName = __filename;
        this.emit('messageTracked', {dir: message});
        this.emit('messageTracked', {file: fileName});
    }
}

export default Tracker;

