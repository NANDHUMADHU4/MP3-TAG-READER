#include<stdio.h>
#include "main.h"
#include "type.h"
#include <string.h>


OperationType check_operation_type(char *argv[])
{
    if (argv[1] != NULL)
    {
	if (strcmp(argv[1],"-v") == 0)
	{
	    return view;

	}
	else if (strcmp(argv[1],"-e") == 0)
	{
	    return edit;
	}
	else if (strcmp(argv[1],"--help")== 0)
	{
	    return help;
	}
    }
    else
    {
	return unsupported;
    }
}














int main(int argc, char *argv[])
{
    MP3Info mp3Info;
    EditInfo editInfo;
    int ret = check_operation_type(argv);
    if (ret == view)
    {
	if (argc == 3)
	{
	    if (read_and_validate(argv,&mp3Info) == success)
	    {
		if (view_operation (&mp3Info) == success)
		{
		    //printf("view success\n");
		}
		else
		{
		    printf("ERROR: View operation Failure\n");
		}
	    }
	    else
	    {
		printf("ERROR: Read and validate Fail\n");
	    }

	}
	else
	{
	    printf("ERROR: Please pass the correct cmdline arguments\n");
	}


    }
    else if (ret == edit)
    {
	if (argc == 5)
	{
	    if (read_and_validate_edit(argv,&editInfo) == success)
	    {
		if (edit_operation(argv,&editInfo) == success)
		{
		   // printf("SUCCESS edit\n");
		}
		else
		{
		    printf("ERROR: Edit operation Failure\n");
		}

	    }
	    else
	    {
		printf("ERROR: Read and validate Fail\n");
	    }

	}
	else
	{
	    printf("ERROR: Please pass the correct cmdline arguments\n");
	}
	
    }





    else if (ret == help)
    {
	printf("-----------------------HELP MENU------------------------\n1. -v -> to view mp3 file contents\n2. -e -> to edit mp3 file contents\n\t 2.1. -t -> to edit song title\n\t2.2. -a -> to edit artist name\nt2.3. -A -> to edit album name\n\t2.4. -y -> to edit year\n\t2.5. -m -> to edit content\n\t2.1. -c -> to edit comment\n----------------------------------------------------------\n");

    }
    else if (ret == unsupported)
    {
	printf("ERROR: ./a.out: INVALID ARGUMENTS\nUSAGE:\nTo view please pass like: ./a.out -v mp3filename\nTo edit please pass like: ./a.out -e-t/-a/-A/-m/-y/-c changing_text mp3filename\nTo get help pass like: ./a.out --help\n");

    }



}

