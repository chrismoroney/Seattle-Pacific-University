const mongoose = require('mongoose');
let Post = require('../models/Post.js');
let Schema = mongoose.Schema;

let ReplySchema = new Schema({
    Name: {type: String, required: true},
    Body: {type: String, required: true},
    Parent: {type: Post, required: true}
});

module.exports = mongoose.model('Reply', ReplySchema);