#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_mmitkov_my_string_compare_returns_0_for_equal_strings(char* buffer, int length);
Status test_mmitkov_get_capacity_returns_one_greater_than_length_with_init_c_string(char* buffer, int length);
Status test_mmitkov_my_string_c_str_returns_valid_c_string(char* buffer, int length);
Status test_mmitkov_my_string_push_back_pushes_char(char* buffer, int length);
Status test_mmitkov_my_string_push_back_allocates_extra_capacity(char* buffer, int length);
Status test_mmitkov_my_string_pop_back_pops_last_char_in_my_string(char* buffer, int length);
Status test_mmitkov_my_string_concat_returns_concatinated_my_string_object(char*buffer, int length);
Status test_mmitkov_my_string_concat_resizes_hResult(char* buffer, int length);
Status test_mmitkov_my_string_concast_does_not_change_hAppend(char* buffer, int length);
Status test_mmitkov_my_string_empty_returns_true_after_init_default(char* buffer, int length);
Status test_mmitkov_my_string_at_returns_null_for_out_of_bounds(char* buffer, int length);
Status test_mmitkov_my_string_at_returns_correct_char(char* buffer, int length);
Status test_mmitkov_my_string_empty_returns_false_after_init_c_str(char* buffer, int length);
Status test_mmitkov_my_string_c_str_returns_null_terminated_cstr(char*buffer, int length);
Status test_mmitkov_get_size_returns_accurate_on_innit_c_string(char*buffer, int length);
Status test_mmitkov_hString_nullptr_after_init_and_my_string_destroy(char* buffer, int length);
Status test_mmitkov_string_extraction_ignores_whitespace_from_str_insertion(char* buffer, int length);
Status my_string_pop_back_returns_FAILURE_after_init_default(char* buffer, int length);
Status my_string_insertion_succesfully_inserts_my_string_into_file(char* buffer, int length);
Status my_string_extraction_extracts_string_no_whitespace(char* buffer, int length);
Status My_string_compare_returns_negative_if_lefthand_smaller(char* buffer, int length);
Status My_string_compare_returns_positive_if_righthand_smaller(char* buffer, int length);
Status my_string_extraction_replaces_data_in_my_string(char*buffer, int lenght);
Status test_get_capacity_on_init_default_returns_7(char* buffer, int length);
#endif
