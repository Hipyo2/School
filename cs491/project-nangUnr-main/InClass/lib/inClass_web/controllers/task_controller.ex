defmodule InClassWeb.TaskController do
  use InClassWeb, :controller

  alias InClass.Repo
  alias InClass.Company
  alias InClass.Company.Task

  def index(conn, _params) do
    tasks = Company.list_tasks()
    render(conn, "index.html", tasks: tasks)
  end

  def new(conn, _params) do
    changeset = Company.change_task(%Task{})
    generalareas = Company.list_generalareas()
    assignments = Company.list_assignments()
    render(conn, "new.html", changeset: changeset, generalareas: generalareas, assignments: assignments)
  end

  def create(conn, %{"task" => task_params}) do
    case Company.create_task(task_params) do
      {:ok, task} ->
        conn
        |> put_flash(:info, "Task created successfully.")
        |> redirect(to: Routes.task_path(conn, :show, task))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    task = Company.get_task!(id) |> Repo.preload(:generalarea) |> Repo.preload([assignments: [:status, [developer: :area]]])
    changeset = Company.change_task(task)
    generalareas = Company.list_generalareas()
    render(conn, "show.html", task: task, changeset: changeset, generalareas: generalareas)
  end

  def edit(conn, %{"id" => id}) do
    task = Company.get_task!(id)
    changeset = Company.change_task(task)
    generalareas = Company.list_generalareas()
    assignments = Company.list_assignments()
    render(conn, "edit.html", task: task, changeset: changeset, generalareas: generalareas, assignments: assignments)
  end

  def update(conn, %{"id" => id, "task" => task_params}) do
    task = Company.get_task!(id)

    case Company.update_task(task, task_params) do
      {:ok, task} ->
        conn
        |> put_flash(:info, "Task updated successfully.")
        |> redirect(to: Routes.task_path(conn, :show, task))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", task: task, changeset: changeset)
    end
  end

  def delete(conn, %{"id" => id}) do
    task = Company.get_task!(id)
    {:ok, _task} = Company.delete_task(task)

    conn
    |> put_flash(:info, "Task deleted successfully.")
    |> redirect(to: Routes.task_path(conn, :index))
  end
end
