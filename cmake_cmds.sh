cmake -DCMAKE_INSTALL_PREFIX=./stage -DHAVE_USELOCALE=0 -DNEWLOCALE_NEEDS_FREELOCALE=0 -DHAVE_SETLOCALE=0 -DENABLE_THREADING=ON -DDISABLE_THREAD_LOCAL_STORAGE=OFF ..
cmake -DCMAKE_INSTALL_PREFIX=./stage ..
cmake -DCMAKE_INSTALL_PREFIX=./stage -DHAVE_USELOCALE=0 -DNEWLOCALE_NEEDS_FREELOCALE=0 -DHAVE_SETLOCALE=0 -DENABLE_THREADING=ON -DDISABLE_THREAD_LOCAL_STORAGE=ON ..