
#include <assert.h>
#include <limits.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#include "json.h"
#include "json_object.h"
#include "parse_flags.h"

static void *thread_do(void *p_n_iter)
{
	long int n_iter = *(long int *)p_n_iter;

	for (long int idx = 0; idx < n_iter; idx++) {

		json_object *obj = json_object_new_object();
		json_object *nested = json_object_new_object();

		json_object_object_add(obj, "abc", json_object_new_int(12));
		json_object_object_add(obj, "foo", json_object_new_string("bar"));
		json_object_object_add(obj, "bool0", json_object_new_boolean(0));
		json_object_object_add(obj, "bool1", json_object_new_boolean(1));
		json_object_object_add(obj, "baz", json_object_new_string("bang"));

		json_object_object_add(nested, "nested_field", json_object_new_string("derp"));

		json_object_object_add(obj, "nest", nested);

		const char *result = json_object_to_json_string_ext(obj, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY);

		printf("\"%s\"\n", result);

		json_object_put(obj);

	}

	return NULL;
}

int main(int argc, char **argv)
{
	long int n_th = 10;
	long int n_iter = 100;

	if (argc >= 2)
		n_iter = atol(argv[1]);

	if (argc >= 3)
		n_th = atol(argv[2]);

	pthread_t *pth = (pthread_t *)calloc(n_th, sizeof(pthread_t));

	for (int idx = 0; idx < n_th; idx++)
		assert(-1 != pthread_create(&pth[idx], NULL, thread_do, (void *)&n_iter));
	for (int idx = 0; idx < n_th; idx++)
		assert(-1 != pthread_join(pth[idx], NULL));

	free(pth);

	return EXIT_SUCCESS;
}
