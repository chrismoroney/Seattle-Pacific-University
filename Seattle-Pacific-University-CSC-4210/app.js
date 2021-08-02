var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var moroneyRouter1 = require('./routes/moroneyDFAM1');
var moroneyRouter2 = require('./routes/moroneyDFAM2');
var moroneyRouter3 = require('./routes/moroneyDFAM3');
var moroneyCustom = require('./routes/custom');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/moroneyDFAM1', moroneyRouter1);
app.use('/moroneyDFAM2', moroneyRouter2);
app.use('/moroneyDFAM3', moroneyRouter3);
app.use('/custom', moroneyCustom);

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
