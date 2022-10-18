//
// Created by zlxx on 2022/10/18.
//

#ifndef MINIDB_UPDATE_OPERATOR_H
#define MINIDB_UPDATE_OPERATOR_H
#pragma once

#include "sql/operator/operator.h"
#include "rc.h"

class Trx;
class UpdateStmt;
class UpdateOperator : public Operator {
public:
  UpdateOperator(UpdateStmt *update_stmt, Trx *trx) : update_stmt_(update_stmt), trx_(trx)
  {}
  RC open() override;
  RC next() override;
  RC close() override;

  Tuple * current_tuple() override {
    return nullptr;
  }
private:
  UpdateStmt *update_stmt_ = nullptr;
  Trx *trx_ = nullptr;
};

#endif  // MINIDB_UPDATE_OPERATOR_H
