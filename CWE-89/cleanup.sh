#!/usr/bin/env bash

# removes all exited containers
docker ps -aq -f status=exited | xargs docker rm

# removes all unnamed images
docker images -q --filter "dangling=true" | xargs docker rmi
