resource "local_file" "b64file" {
  filename = "/tmp/file.txt"
  content_base64 = base64encode("this is a test")
}