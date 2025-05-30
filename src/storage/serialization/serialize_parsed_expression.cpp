//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/serializer.hpp"
#include "duckdb/common/serializer/deserializer.hpp"
#include "duckdb/parser/expression/list.hpp"

namespace duckdb {

void ParsedExpression::Serialize(Serializer &serializer) const {
	serializer.WriteProperty<ExpressionClass>(100, "class", expression_class);
	serializer.WriteProperty<ExpressionType>(101, "type", type);
	serializer.WritePropertyWithDefault<string>(102, "alias", alias);
	serializer.WritePropertyWithDefault<optional_idx>(103, "query_location", query_location, optional_idx());
}

unique_ptr<ParsedExpression> ParsedExpression::Deserialize(Deserializer &deserializer) {
	auto expression_class = deserializer.ReadProperty<ExpressionClass>(100, "class");
	auto type = deserializer.ReadProperty<ExpressionType>(101, "type");
	auto alias = deserializer.ReadPropertyWithDefault<string>(102, "alias");
	auto query_location = deserializer.ReadPropertyWithExplicitDefault<optional_idx>(103, "query_location", optional_idx());
	deserializer.Set<ExpressionType>(type);
	unique_ptr<ParsedExpression> result;
	switch (expression_class) {
	case ExpressionClass::BETWEEN:
		result = BetweenExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::CASE:
		result = CaseExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::CAST:
		result = CastExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::COLLATE:
		result = CollateExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::COLUMN_REF:
		result = ColumnRefExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::COMPARISON:
		result = ComparisonExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::CONJUNCTION:
		result = ConjunctionExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::CONSTANT:
		result = ConstantExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::DEFAULT:
		result = DefaultExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::FUNCTION:
		result = FunctionExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::LAMBDA:
		result = LambdaExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::LAMBDA_REF:
		result = LambdaRefExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::OPERATOR:
		result = OperatorExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::PARAMETER:
		result = ParameterExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::POSITIONAL_REFERENCE:
		result = PositionalReferenceExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::STAR:
		result = StarExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::SUBQUERY:
		result = SubqueryExpression::Deserialize(deserializer);
		break;
	case ExpressionClass::WINDOW:
		result = WindowExpression::Deserialize(deserializer);
		break;
	default:
		throw SerializationException("Unsupported type for deserialization of ParsedExpression!");
	}
	deserializer.Unset<ExpressionType>();
	result->alias = std::move(alias);
	result->query_location = query_location;
	return result;
}

void BetweenExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(200, "input", input);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(201, "lower", lower);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(202, "upper", upper);
}

unique_ptr<ParsedExpression> BetweenExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<BetweenExpression>(new BetweenExpression());
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(200, "input", result->input);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(201, "lower", result->lower);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(202, "upper", result->upper);
	return std::move(result);
}

void CaseExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<vector<CaseCheck>>(200, "case_checks", case_checks);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(201, "else_expr", else_expr);
}

unique_ptr<ParsedExpression> CaseExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<CaseExpression>(new CaseExpression());
	deserializer.ReadPropertyWithDefault<vector<CaseCheck>>(200, "case_checks", result->case_checks);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(201, "else_expr", result->else_expr);
	return std::move(result);
}

void CastExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(200, "child", child);
	serializer.WriteProperty<LogicalType>(201, "cast_type", cast_type);
	serializer.WritePropertyWithDefault<bool>(202, "try_cast", try_cast);
}

unique_ptr<ParsedExpression> CastExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<CastExpression>(new CastExpression());
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(200, "child", result->child);
	deserializer.ReadProperty<LogicalType>(201, "cast_type", result->cast_type);
	deserializer.ReadPropertyWithDefault<bool>(202, "try_cast", result->try_cast);
	return std::move(result);
}

void CollateExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(200, "child", child);
	serializer.WritePropertyWithDefault<string>(201, "collation", collation);
}

unique_ptr<ParsedExpression> CollateExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<CollateExpression>(new CollateExpression());
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(200, "child", result->child);
	deserializer.ReadPropertyWithDefault<string>(201, "collation", result->collation);
	return std::move(result);
}

void ColumnRefExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<vector<string>>(200, "column_names", column_names);
}

unique_ptr<ParsedExpression> ColumnRefExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<ColumnRefExpression>(new ColumnRefExpression());
	deserializer.ReadPropertyWithDefault<vector<string>>(200, "column_names", result->column_names);
	return std::move(result);
}

void ComparisonExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(200, "left", left);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(201, "right", right);
}

unique_ptr<ParsedExpression> ComparisonExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<ComparisonExpression>(new ComparisonExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(200, "left", result->left);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(201, "right", result->right);
	return std::move(result);
}

void ConjunctionExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(200, "children", children);
}

unique_ptr<ParsedExpression> ConjunctionExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<ConjunctionExpression>(new ConjunctionExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadPropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(200, "children", result->children);
	return std::move(result);
}

void ConstantExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WriteProperty<Value>(200, "value", value);
}

unique_ptr<ParsedExpression> ConstantExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<ConstantExpression>(new ConstantExpression());
	deserializer.ReadProperty<Value>(200, "value", result->value);
	return std::move(result);
}

void DefaultExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
}

unique_ptr<ParsedExpression> DefaultExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<DefaultExpression>(new DefaultExpression());
	return std::move(result);
}

void FunctionExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<string>(200, "function_name", function_name);
	serializer.WritePropertyWithDefault<string>(201, "schema", schema);
	serializer.WritePropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(202, "children", children);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(203, "filter", filter);
	serializer.WritePropertyWithDefault<unique_ptr<OrderModifier>>(204, "order_bys", order_bys);
	serializer.WritePropertyWithDefault<bool>(205, "distinct", distinct);
	serializer.WritePropertyWithDefault<bool>(206, "is_operator", is_operator);
	serializer.WritePropertyWithDefault<bool>(207, "export_state", export_state);
	serializer.WritePropertyWithDefault<string>(208, "catalog", catalog);
}

unique_ptr<ParsedExpression> FunctionExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<FunctionExpression>(new FunctionExpression());
	deserializer.ReadPropertyWithDefault<string>(200, "function_name", result->function_name);
	deserializer.ReadPropertyWithDefault<string>(201, "schema", result->schema);
	deserializer.ReadPropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(202, "children", result->children);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(203, "filter", result->filter);
	auto order_bys = deserializer.ReadPropertyWithDefault<unique_ptr<ResultModifier>>(204, "order_bys");
	result->order_bys = unique_ptr_cast<ResultModifier, OrderModifier>(std::move(order_bys));
	deserializer.ReadPropertyWithDefault<bool>(205, "distinct", result->distinct);
	deserializer.ReadPropertyWithDefault<bool>(206, "is_operator", result->is_operator);
	deserializer.ReadPropertyWithDefault<bool>(207, "export_state", result->export_state);
	deserializer.ReadPropertyWithDefault<string>(208, "catalog", result->catalog);
	return std::move(result);
}

void LambdaExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(200, "lhs", lhs);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(201, "expr", expr);
	if (serializer.ShouldSerialize(5)) {
		serializer.WritePropertyWithDefault<LambdaSyntaxType>(202, "syntax_type", syntax_type, LambdaSyntaxType::SINGLE_ARROW_STORAGE);
	}
}

unique_ptr<ParsedExpression> LambdaExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<LambdaExpression>(new LambdaExpression());
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(200, "lhs", result->lhs);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(201, "expr", result->expr);
	deserializer.ReadPropertyWithExplicitDefault<LambdaSyntaxType>(202, "syntax_type", result->syntax_type, LambdaSyntaxType::SINGLE_ARROW_STORAGE);
	return std::move(result);
}

void LambdaRefExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<idx_t>(200, "lambda_idx", lambda_idx);
	serializer.WritePropertyWithDefault<string>(201, "column_name", column_name);
}

unique_ptr<ParsedExpression> LambdaRefExpression::Deserialize(Deserializer &deserializer) {
	auto lambda_idx = deserializer.ReadPropertyWithDefault<idx_t>(200, "lambda_idx");
	auto column_name = deserializer.ReadPropertyWithDefault<string>(201, "column_name");
	auto result = duckdb::unique_ptr<LambdaRefExpression>(new LambdaRefExpression(lambda_idx, std::move(column_name)));
	return std::move(result);
}

void OperatorExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(200, "children", children);
}

unique_ptr<ParsedExpression> OperatorExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<OperatorExpression>(new OperatorExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadPropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(200, "children", result->children);
	return std::move(result);
}

void ParameterExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<string>(200, "identifier", identifier);
}

unique_ptr<ParsedExpression> ParameterExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<ParameterExpression>(new ParameterExpression());
	deserializer.ReadPropertyWithDefault<string>(200, "identifier", result->identifier);
	return std::move(result);
}

void PositionalReferenceExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<idx_t>(200, "index", index);
}

unique_ptr<ParsedExpression> PositionalReferenceExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<PositionalReferenceExpression>(new PositionalReferenceExpression());
	deserializer.ReadPropertyWithDefault<idx_t>(200, "index", result->index);
	return std::move(result);
}

void StarExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<string>(200, "relation_name", relation_name);
	serializer.WriteProperty<case_insensitive_set_t>(201, "exclude_list", SerializedExcludeList());
	serializer.WritePropertyWithDefault<case_insensitive_map_t<unique_ptr<ParsedExpression>>>(202, "replace_list", replace_list);
	serializer.WritePropertyWithDefault<bool>(203, "columns", columns);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(204, "expr", expr);
	/* [Deleted] (bool) "unpacked" */
	serializer.WritePropertyWithDefault<qualified_column_set_t>(206, "qualified_exclude_list", SerializedQualifiedExcludeList(), qualified_column_set_t());
	serializer.WritePropertyWithDefault<qualified_column_map_t<string>>(207, "rename_list", rename_list, qualified_column_map_t<string>());
}

unique_ptr<ParsedExpression> StarExpression::Deserialize(Deserializer &deserializer) {
	auto relation_name = deserializer.ReadPropertyWithDefault<string>(200, "relation_name");
	auto exclude_list = deserializer.ReadProperty<case_insensitive_set_t>(201, "exclude_list");
	auto replace_list = deserializer.ReadPropertyWithDefault<case_insensitive_map_t<unique_ptr<ParsedExpression>>>(202, "replace_list");
	auto columns = deserializer.ReadPropertyWithDefault<bool>(203, "columns");
	auto expr = deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(204, "expr");
	auto unpacked = deserializer.ReadPropertyWithExplicitDefault<bool>(205, "unpacked", false);
	auto qualified_exclude_list = deserializer.ReadPropertyWithExplicitDefault<qualified_column_set_t>(206, "qualified_exclude_list", qualified_column_set_t());
	auto rename_list = deserializer.ReadPropertyWithExplicitDefault<qualified_column_map_t<string>>(207, "rename_list", qualified_column_map_t<string>());
	auto result = StarExpression::DeserializeStarExpression(std::move(relation_name), exclude_list, std::move(replace_list), columns, std::move(expr), unpacked, qualified_exclude_list, std::move(rename_list));
	return result;
}

void SubqueryExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WriteProperty<SubqueryType>(200, "subquery_type", subquery_type);
	serializer.WritePropertyWithDefault<unique_ptr<SelectStatement>>(201, "subquery", subquery);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(202, "child", child);
	serializer.WriteProperty<ExpressionType>(203, "comparison_type", comparison_type);
}

unique_ptr<ParsedExpression> SubqueryExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<SubqueryExpression>(new SubqueryExpression());
	deserializer.ReadProperty<SubqueryType>(200, "subquery_type", result->subquery_type);
	deserializer.ReadPropertyWithDefault<unique_ptr<SelectStatement>>(201, "subquery", result->subquery);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(202, "child", result->child);
	deserializer.ReadProperty<ExpressionType>(203, "comparison_type", result->comparison_type);
	return std::move(result);
}

void WindowExpression::Serialize(Serializer &serializer) const {
	ParsedExpression::Serialize(serializer);
	serializer.WritePropertyWithDefault<string>(200, "function_name", function_name);
	serializer.WritePropertyWithDefault<string>(201, "schema", schema);
	serializer.WritePropertyWithDefault<string>(202, "catalog", catalog);
	serializer.WritePropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(203, "children", children);
	serializer.WritePropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(204, "partitions", partitions);
	serializer.WritePropertyWithDefault<vector<OrderByNode>>(205, "orders", orders);
	serializer.WriteProperty<WindowBoundary>(206, "start", start);
	serializer.WriteProperty<WindowBoundary>(207, "end", end);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(208, "start_expr", start_expr);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(209, "end_expr", end_expr);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(210, "offset_expr", offset_expr);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(211, "default_expr", default_expr);
	serializer.WritePropertyWithDefault<bool>(212, "ignore_nulls", ignore_nulls);
	serializer.WritePropertyWithDefault<unique_ptr<ParsedExpression>>(213, "filter_expr", filter_expr);
	serializer.WritePropertyWithDefault<WindowExcludeMode>(214, "exclude_clause", exclude_clause, WindowExcludeMode::NO_OTHER);
	serializer.WritePropertyWithDefault<bool>(215, "distinct", distinct);
	serializer.WritePropertyWithDefault<vector<OrderByNode>>(216, "arg_orders", arg_orders);
}

unique_ptr<ParsedExpression> WindowExpression::Deserialize(Deserializer &deserializer) {
	auto result = duckdb::unique_ptr<WindowExpression>(new WindowExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadPropertyWithDefault<string>(200, "function_name", result->function_name);
	deserializer.ReadPropertyWithDefault<string>(201, "schema", result->schema);
	deserializer.ReadPropertyWithDefault<string>(202, "catalog", result->catalog);
	deserializer.ReadPropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(203, "children", result->children);
	deserializer.ReadPropertyWithDefault<vector<unique_ptr<ParsedExpression>>>(204, "partitions", result->partitions);
	deserializer.ReadPropertyWithDefault<vector<OrderByNode>>(205, "orders", result->orders);
	deserializer.ReadProperty<WindowBoundary>(206, "start", result->start);
	deserializer.ReadProperty<WindowBoundary>(207, "end", result->end);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(208, "start_expr", result->start_expr);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(209, "end_expr", result->end_expr);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(210, "offset_expr", result->offset_expr);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(211, "default_expr", result->default_expr);
	deserializer.ReadPropertyWithDefault<bool>(212, "ignore_nulls", result->ignore_nulls);
	deserializer.ReadPropertyWithDefault<unique_ptr<ParsedExpression>>(213, "filter_expr", result->filter_expr);
	deserializer.ReadPropertyWithExplicitDefault<WindowExcludeMode>(214, "exclude_clause", result->exclude_clause, WindowExcludeMode::NO_OTHER);
	deserializer.ReadPropertyWithDefault<bool>(215, "distinct", result->distinct);
	deserializer.ReadPropertyWithDefault<vector<OrderByNode>>(216, "arg_orders", result->arg_orders);
	return std::move(result);
}

} // namespace duckdb
