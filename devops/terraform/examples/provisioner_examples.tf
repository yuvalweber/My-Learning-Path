resource "aws_instance" "web" {
  provisioner "remote-exec" {
    when = create
    command = "echo this is a test command running on ${self.private_ip}"
  }
  provisioner "file" {
    source = "/tmp/source.txt"
    destination = "/tmp/destination.txt"
    when = create
  }
  connection {
    type = "ssh"
    user = "root"
    password = "${var.root_password}"
    host = "${var.host}"
  }
}