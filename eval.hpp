#ifndef EVAL_H
#define EVAL_H

#include "parser.hpp"
#include <boost/shared_ptr.hpp>

class SchemeObject;

typedef ASTPtr Expression;
typedef shared_ptr<SchemeObject> SchemeObjectPtr;

class SchemeObject {
};

class Environment {
};

class Interpreter {
private:
  bool self_evaluating(Expression expr);
  bool variable(Expression expr);
  bool quoted(Expression expr);
  bool assignment(Expression expr);
  bool definition(Expression expr);
  bool is_if(Expression expr);
  bool lambda(Expression expr);
  bool begin(Expression expr);
  bool cond(Expression expr);
  bool application(Expression expr);
  SchemeObjectPtr value(Expression expr);
  SchemeObjectPtr lookup_variable_value(Expression expr, Environment &env);
  SchemeObjectPtr text_of_quotation(Expression expr);
  SchemeObjectPtr eval_assignment(Expression expr, Environment &env);
  SchemeObjectPtr eval_definition(Expression expr, Environment &env);
  SchemeObjectPtr eval_if(Expression expr, Environment &env);
  SchemeObjectPtr make_procedure(SchemeObjectPtr params, SchemeObjectPtr body, Environment &env);
  SchemeObjectPtr lambda_parameters(Expression expr);
  SchemeObjectPtr lambda_body(Expression expr);
  SchemeObjectPtr eval_sequence(SchemeObjectPtr sequence, Environment &env);
  SchemeObjectPtr begin_actions(Expression expr);
  Expression cond_to_if(Expression expr);
  SchemeObjectPtr apply(SchemeObjectPtr func, SchemeObjectPtr arguments);
  Expression the_operator(Expression exp);
  Expression operands(Expression exp);
  SchemeObjectPtr list_of_values(Expression exp, Environment &env);

public:
  SchemeObjectPtr eval(Expression exp, Environment &env);
};

#endif
