defmodule Cs491Hm1Web.ComputerController do
  use Cs491Hm1Web, :controller

  alias Cs491Hm1.OfficeAssets
  alias Cs491Hm1.OfficeAssets.Computer

  def index(conn, _params) do
    computer = OfficeAssets.list_computer()
    render(conn, "index.html", computer: computer)
  end

  def new(conn, _params) do
    changeset = OfficeAssets.change_computer(%Computer{})
    render(conn, "new.html", changeset: changeset)
  end

  def create(conn, %{"computer" => computer_params}) do
    case OfficeAssets.create_computer(computer_params) do
      {:ok, computer} ->
        conn
        |> put_flash(:info, "Computer created successfully.")
        |> redirect(to: Routes.computer_path(conn, :show, computer))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    computer = OfficeAssets.get_computer!(id)
    render(conn, "show.html", computer: computer)
  end

  def edit(conn, %{"id" => id}) do
    computer = OfficeAssets.get_computer!(id)
    changeset = OfficeAssets.change_computer(computer)
    render(conn, "edit.html", computer: computer, changeset: changeset)
  end

  def update(conn, %{"id" => id, "computer" => computer_params}) do
    computer = OfficeAssets.get_computer!(id)

    case OfficeAssets.update_computer(computer, computer_params) do
      {:ok, computer} ->
        conn
        |> put_flash(:info, "Computer updated successfully.")
        |> redirect(to: Routes.computer_path(conn, :show, computer))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", computer: computer, changeset: changeset)
    end
  end

  def delete(conn, %{"id" => id}) do
    computer = OfficeAssets.get_computer!(id)
    {:ok, _computer} = OfficeAssets.delete_computer(computer)

    conn
    |> put_flash(:info, "Computer deleted successfully.")
    |> redirect(to: Routes.computer_path(conn, :index))
  end
end
