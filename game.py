import turtle, random

# Setup screen and paddle
paddle = turtle.Turtle()
paddle.shape("square")
paddle.color("blue")
paddle.penup()
paddle.goto(0, -150)

# Ball setup
ball = turtle.Turtle()
ball.shape("circle")
ball.color("red")
ball.penup()
ball.goto(random.randint(-150, 150), 150)

score = 0  # starting score

# Move paddle left
def left():
    if paddle.xcor() > -200:
        paddle.setx(paddle.xcor() - 20)

# Move paddle right
def right():
    if paddle.xcor() < 200:
        paddle.setx(paddle.xcor() + 20)

# Move the ball down
def drop_ball():
    global score
    ball.sety(ball.ycor() - 5)

    # If ball hits paddle
    if ball.ycor() < -140 and abs(ball.xcor() - paddle.xcor()) < 20:
        score += 1
        print("Score:", score)
        ball.goto(random.randint(-150, 150), 150)

    # If ball misses paddle
    elif ball.ycor() < -200:
        print("Game Over! Final Score:", score)
        turtle.bye()
        return

    turtle.ontimer(drop_ball, 50)  # keep ball moving

# Keyboard controls
turtle.listen()
turtle.onkeypress(left, "Left")
turtle.onkeypress(right, "Right")

# Start the game
drop_ball()
turtle.mainloop()
#pip install PythonTurtle
