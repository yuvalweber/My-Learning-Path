variable "web_bucket_name" {
  default = "s3-terraform-web-yuval"
  description = "bucket name for staticWebsite"
  type = string
}

variable "content_types" {
  default = {
    js   =  "application/javascript"
    html =  "text/html"
    txt  =  "text/plain"
    json =  "application/json"
    ico  =  "image/x-icon"
    svg  =  "image/svg+xml"
    css  =  "text/css"
    jpg  =  "image/jpeg"
    jpeg =  "image/jpeg"
    png  =  "image/png"
    txt  =  "text/plain"
    map  =  "binary/octet-stream"
  }
  description = "content types for different files"
  type = map(string)
}