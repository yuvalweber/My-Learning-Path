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

# null resource meant for running scripts without resource
resource "null_resource" "example_provisioner_null" {
  # when the value in the trigger changed the provisioner runs
  triggers = {
    id = "${local_file.bool_expression_file.id}"
  }

  provisioner "remote-exec" {
    inline = [
      "echo test provisioner"
    ]
  }

  connection {
    type = "ssh"
    user = "root"
    password = random_password.generated_pass.result
    host = "127.0.0.1"
  }
}