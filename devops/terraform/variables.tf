variable "filename" {
  type = map(any)
  default = {
    first  = "/root/example.txt"
    second = "/root/example2.txt"
  }
  description = "the name of the file"
}

variable "content" {
  default     = "example string..."
  type        = string
  description = "the content of the file"
}

variable "random_string_files" {
  type = list(string)
  default = [ "dani", "din", "was", "here" ]
}

variable "random_string_files_count" {
  type = list(string)
  default = [ "dani", "din", "was", "here" ]
}

variable "length" {
  default = ["10", "12", "16"]
  type    = list(number)
}

variable "example_object" {
  type = object({
    name    = string
    color   = string
    age     = number
    food    = list(string)
    is_good = bool
  })

  default = {
    age     = 22
    color   = "green"
    food    = ["pizza", "hamburger"]
    is_good = true
    name    = "yuval weber"
  }
}

variable "example_tuple" {
  type    = tuple([string, number, bool])
  default = ["cat", 1, false]
}

variable "example_set" {
  type    = set(string)
  default = ["banana", "apple"]
}