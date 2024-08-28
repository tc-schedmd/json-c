
#include <assert.h>
#include <limits.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#include "json.h"
#include "parse_flags.h"

static void *thread_do(void *)
{
	json_object *new_obj;

	new_obj = json_tokener_parse(
	    "/* more difficult test case */"
	    "{ \"glossary\": { \"title\": \"example glossary\", \"GlossDiv\": { \"title\": \"S\", "
	    "\"GlossList\": [ { \"ID\": \"SGML\", \"SortAs\": \"SGML\", \"GlossTerm\": \"Standard "
	    "Generalized Markup Language\", \"Acronym\": \"SGML\", \"Abbrev\": \"ISO 8879:1986\", "
	    "\"GlossDef\": \"A meta-markup language, used to create markup languages such as "
	    "DocBook.\", \"GlossSeeAlso\": [\"GML\", \"XML\", \"markup\"] } ] } } }");

	json_object_put(new_obj);

	return NULL;
}

int main(int argc, char **argv)
{
	const int num_th = 10;
	pthread_t pth[num_th];
	for (int idx = 0; idx < num_th; idx++)
		assert(-1 != pthread_create(&pth[idx], NULL, thread_do, NULL));
	for (int idx = 0; idx < num_th; idx++)
		assert(-1 != pthread_join(pth[idx], NULL));
	return EXIT_SUCCESS;
}
