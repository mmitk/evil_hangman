#include <stdio.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{
Status (*tests[])(char*, int) =
{
	test_get_size_on_init_default_returns_0,
	test_mmitkov_my_string_compare_returns_0_for_equal_strings,
	test_mmitkov_get_capacity_returns_one_greater_than_length_with_init_c_string,
	test_mmitkov_my_string_c_str_returns_valid_c_string,
	test_mmitkov_my_string_push_back_pushes_char,
	test_mmitkov_my_string_push_back_allocates_extra_capacity,
	test_mmitkov_my_string_pop_back_pops_last_char_in_my_string,
	test_mmitkov_my_string_concat_returns_concatinated_my_string_object,
	test_mmitkov_my_string_concat_resizes_hResult,
	test_mmitkov_my_string_concast_does_not_change_hAppend,
	test_mmitkov_my_string_empty_returns_true_after_init_default,
	test_mmitkov_my_string_at_returns_null_for_out_of_bounds,
	test_mmitkov_my_string_at_returns_correct_char,
	test_mmitkov_my_string_empty_returns_false_after_init_c_str,
	test_mmitkov_my_string_c_str_returns_null_terminated_cstr,
	test_mmitkov_get_size_returns_accurate_on_innit_c_string,
	test_mmitkov_hString_nullptr_after_init_and_my_string_destroy,
	test_mmitkov_string_extraction_ignores_whitespace_from_str_insertion,
	my_string_pop_back_returns_FAILURE_after_init_default,
	my_string_insertion_succesfully_inserts_my_string_into_file,
	my_string_extraction_extracts_string_no_whitespace,
	My_string_compare_returns_negative_if_lefthand_smaller,
	My_string_compare_returns_positive_if_righthand_smaller,
	my_string_extraction_replaces_data_in_my_string,
	test_get_capacity_on_init_default_returns_7

};
int number_of_functions = sizeof(tests) / sizeof(tests[0]);
int i;
char buffer[500];
int success_count = 0;
int failure_count = 0;
for(i=0; i<number_of_functions; i++)
{
if(tests[i](buffer, 500) == FAILURE)
{
printf("FAILED: Test %d failed miserably\n", i);
printf("\t%s\n", buffer);
failure_count++;
}
else
{
// printf("PASS: Test %d passed\n", i);
// printf("\t%s\n", buffer);
success_count++;
}
}
printf("Total number of tests: %d\n", number_of_functions);
printf("%d/%d Pass, %d/%d Failure\n", success_count,
number_of_functions, failure_count, number_of_functions);
return 0;
}

