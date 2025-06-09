#!/bin/bash

if [ -z "$1" ]; then
  echo "Erreur : need gitlab user token (with api right)"
  echo "Usage : $0 <token>"
  exit 1
fi

GITLAB_TOKEN=$1
GITLAB_URL="http://gitlab.local"
NAMESPACE="root"
PROJECT_NAME="njegat_iot_website"
LOCAL_DIR="./tmp_git"

response=$(curl --silent --show-error --fail --request POST "$GITLAB_URL/api/v4/projects" \
  --header "PRIVATE-TOKEN: $GITLAB_TOKEN" \
  --form "name=$PROJECT_NAME" \
  --form "namespace_id=$(curl --silent --header "PRIVATE-TOKEN: $GITLAB_TOKEN" "$GITLAB_URL/api/v4/namespaces?search=$NAMESPACE" | jq '.[0].id')" \
  --form "initialize_with_readme=false" \
  --form "visibility=public")

mkdir -p "$LOCAL_DIR"
cd "$LOCAL_DIR"
git init
cp -r ../repo_content/* .
git commit -m "Initial commit"
git remote add origin https://oauth2:$GITLAB_TOKEN@gitlab.local/root/$PROJECT_NAME.git
git push -u origin master