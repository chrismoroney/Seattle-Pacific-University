var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var cors = require('cors');
var bodyParser = require('body-parser');
var session = require('express-session')
var app = express();
var $ = require('jquery');
require('dotenv').config({path:'./env'});

app.use(session({
  secret: 'keyboard cat',
  name: 'uniqueSessionId',
  resave: false,
  saveUninitialized: false,
  cookie: { secure: false }
}))

//connect to db
var db = require('./database');

var loginRouter = require('./routes/login');
var messengerRouter = require('./routes/messenger');
var postsRouter = require('./routes/posts');
var homepageRouter = require('./routes/homepage');
var myprofileRouter = require('./routes/myprofile');
var createprofileRouter = require('./routes/createprofile');
var editprofileRouter = require('./routes/editprofile');
var searchprofileRouter = require('./routes/searchprofile');
var authenticationRouter = require('./routes/authenticate');
var chatListRouter = require('./routes/chats');
var logoutRouter = require('./routes/logout');
var videoChatRouter = require('./routes/room');
var otherprofileRouter = require('./routes/otherprofile');
var viewfollowingRouter = require('./routes/viewfollowing');
var viewblockedRouter = require('./routes/viewblocked');
var profilepicsRouter = require('./routes/profilepics');
var uploadimgRouter = require('./routes/upload');
var replyRouter = require('./routes/replyBox');


require('dotenv').config();

// view engine setup

app.use(bodyParser.urlencoded({extended: true}));

//commented out for video chat
app.engine('html', require('ejs').renderFile);
app.set('view engine', 'html');

/* uncommented for video chat */
// app.set('view engine', 'ejs');
// app.use(express.static('public'))

//commented out for video chat
app.set('views', path.join(__dirname, 'views'));

app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use(express.static('profileImages'));
app.use('/profileImages', express.static('profileImages'));

app.use(bodyParser.json());

app.use('/', loginRouter);
app.use('/messenger', messengerRouter);
app.use('/posts', postsRouter);
app.use('/homepage', homepageRouter);
app.use('/myprofile', myprofileRouter);
app.use('/createprofile', createprofileRouter);
app.use('/editprofile', editprofileRouter);
app.use('/searchprofile', searchprofileRouter);
app.use('/authenticate', authenticationRouter);
app.use('/chats', chatListRouter);
app.use('/logout', logoutRouter);
app.use('/videochat', videoChatRouter);
app.use('/otherprofile', otherprofileRouter);
app.use('/viewfollowing', viewfollowingRouter);
app.use('/viewblocked', viewblockedRouter);
app.use('/profilepics', profilepicsRouter);
app.use('/upload', uploadimgRouter);
app.use('/reply', replyRouter);


// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;