terraform {
  backend "s3" {
    bucket = "s3-terraform-state-yuval"
    region = "eu-central-1"
    key = "terraform.tfstate"
    dynamodb_table = "terraform-tfstate"
    encrypt = true 
  }
  required_providers {
    aws = {
      source  = "hashicorp/aws"
      version = ">= 3.20.0"
    }
  }
}

provider "aws" {
  region = "eu-central-1"
}