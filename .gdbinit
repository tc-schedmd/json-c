define watch_obj_field_name
  break json_tokener.c:1258
  commands
    printf "obj_field_name %llx %s\n", tok->stack[tok->depth].obj_field_name, tok->stack[tok->depth].obj_field_name
    c
  end
end

break main
break test2.c:41
