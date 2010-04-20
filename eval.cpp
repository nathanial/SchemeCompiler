#include "eval.hpp"
#include <stdio.h>


SchemeObjectPtr Interpreter::eval(Expression exp, Environment &env){
  if(self_evaluating(exp)) {
    return value(exp);
  } 
  else if(variable(exp)){
    return lookup_variable_value(exp, env);
  }
  else if(quoted(exp)){
    return text_of_quotation(exp);
  }
  else if(assignment(exp)) {
    return eval_assignment(exp, env);
  }
  else if(definition(exp)){
    return eval_definition(exp, env);
  }
  else if(is_if(exp)){
    return eval_if(exp, env);
  }
  else if(lambda(exp)){
    SchemeObjectPtr params = lambda_parameters(exp);
    SchemeObjectPtr body = lambda_body(exp);
    return make_procedure(params, body, env);
  }
  else if(begin(exp)){
    return eval_sequence(begin_actions(exp), env);
  }
  else if(cond(exp)){
    Expression cexp = cond_to_if(exp);
    return eval(cexp, env);
  }
  else if(application(exp)){
    Expression op = the_operator(exp);
    Expression ops = operands(exp);
    SchemeObjectPtr arguments = list_of_values(ops, env);
    return apply(eval(op, env), arguments);
  } else {
    throw "Unknown expression type -- EVAL";
  }
}

bool Interpreter::self_evaluating(Expression expr){
  return false;
}

bool Interpreter::variable(Expression expr){
  return false;
}

bool Interpreter::quoted(Expression expr){
  return false;
}

bool Interpreter::assignment(Expression expr){
  return false;
}

bool Interpreter::definition(Expression expr){
  return false;
}

bool Interpreter::is_if(Expression expr){
  return false;
}

bool Interpreter::lambda(Expression expr){
  return false;
}

bool Interpreter::begin(Expression expr){
  return false;
}

bool Interpreter::cond(Expression expr){
  return false;
}

bool Interpreter::application(Expression expr){  
  return false;
}

SchemeObjectPtr Interpreter::value(Expression expr){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::lookup_variable_value(Expression expr, Environment &env){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::text_of_quotation(Expression expr){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::eval_assignment(Expression expr, Environment &env){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::eval_definition(Expression expr, Environment &env){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::eval_if(Expression expr, Environment &env){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::make_procedure(SchemeObjectPtr params, SchemeObjectPtr body, Environment &env){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::lambda_parameters(Expression expr){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::lambda_body(Expression expr){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::eval_sequence(SchemeObjectPtr sequence, Environment &env){
  return SchemeObjectPtr();
}

SchemeObjectPtr Interpreter::begin_actions(Expression expr){
  return SchemeObjectPtr();
}

Expression Interpreter::cond_to_if(Expression expr){
  return Expression();
}

SchemeObjectPtr Interpreter::apply(SchemeObjectPtr func, SchemeObjectPtr arguments){
  return SchemeObjectPtr();
}

Expression Interpreter::the_operator(Expression exp){
  return Expression();
}

Expression Interpreter::operands(Expression exp){
  return Expression();
}

SchemeObjectPtr Interpreter::list_of_values(Expression exp, Environment &env){
  return SchemeObjectPtr();
}
