cmake_minimum_required(VERSION 3.16)
project(Gestiune-activitati)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gestiune-activitati main.cpp Console/ui.h Console/ui.h Console/ui.cpp Tests/tests.cpp Tests/tests.h Business/service.cpp Business/service.h Repo/repo.h Repo/repo.cpp Domain/activitate.h Domain/activitate.cpp Validator/validate.cpp Validator/validate.h)
