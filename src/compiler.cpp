#include "compiler.h"

static std::unique_ptr<Module> *module;
static IRBuilder<> builder(getGlobalContext());
static std::map<std::string, Value*> values;

Value compErr(const char *msg, const char *errSrc){
    fprintf(stderr, msg, errSrc);
    return NULL;
}


Value* comp_floatLit(Token val){
    return ConstantFP::get(getGlobalContext(), APFloat(val));
}

Value* comp_var(Token val){
    Value *var = values[val.lexeme];
    if(!var)
        return compErr(COMP_NDEF_ERR, val.lexeme);
    return var;
}

extern "C" void* compile(Token *tok){
    return tok;
}
