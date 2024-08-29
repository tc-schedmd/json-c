define watch_obj_field_name
  break json_tokener.c:1258
  commands
    printf "obj_field_name %llx %s\n", tok->stack[tok->depth].obj_field_name, tok->stack[tok->depth].obj_field_name
    c
  end
end

# watch_mem
# watch_obj_field_name
# break main
# next
# run
